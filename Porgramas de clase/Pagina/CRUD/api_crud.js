const api = new API("https://crudcrud.com/api/9ffb5107f2fa46dcaddf746b200ddb3a");

document.addEventListener("DOMContentLoaded", () => {
    loadUsers();
});

async function loadUsers() {
    const users = await api.getAll();
    const tbody = document.querySelector("tbody");
    tbody.innerHTML = "";
    users.forEach((user, index) => {
        tbody.innerHTML += `
            <tr id="row-${user._id}">
                <td>${index + 1}</td>
                <td>${user.name}</td>
                <td>${user.email}</td>
                <td>
                    <button class="btn btn-warning btn-sm me-2" onclick="editUser('${user._id}')" data-bs-toggle="modal" data-bs-target="#exampleModal">Edit</button>
                    <button class="btn btn-danger btn-sm" onclick="deleteUser('${user._id}')">Eliminate</button>
                </td>
            </tr>
        `;
    });
}

// Referencias a los inputs
const nameInput = document.querySelector("input[placeholder='Username']");
const emailInput = document.querySelector("input[placeholder='email']");
const saveButton = document.querySelector(".btn-primary");
let editingUserId = null; // Variable para manejar edición de usuario

saveButton.addEventListener("click", async () => {
    const name = nameInput.value.trim();
    const email = emailInput.value.trim();
    
    if (!name || !email) {
        alert("Por favor, llena todos los campos.");
        return;
    }

    if (editingUserId) {
        await api.update(editingUserId, { name, email });
        loadUsers(); // Recargar la tabla con la información actualizada
        editingUserId = null;
        saveButton.textContent = "Save changes";
    } else {
        const newUser = await api.create({ name, email });
        loadUsers(); // Recargar la tabla con el nuevo usuario
    }
    
    clearForm();
    bootstrap.Modal.getInstance(document.getElementById('exampleModal')).hide(); // Cerrar modal
});

async function deleteUser(id) {
    await api.delete(id);
    loadUsers(); // Recargar la tabla tras eliminar el usuario
}

async function editUser(id) {
    const user = await api.get(id);
    if (user) {
        nameInput.value = user.name;
        emailInput.value = user.email;
        editingUserId = id;
        saveButton.textContent = "Update";
    }
}
function clearForm() {
    nameInput.value = "";
    emailInput.value = "";
}

// Add your existing JavaScript code here

// Add your existing JavaScript code here

function saveUser() {
    const username = document.querySelector('.modal-body input[type="text"]').value;
    const email = document.querySelector('.modal-body input[type="email"]').value;
  
    if (username && email) {
      const tableBody = document.querySelector('table tbody');
      const newRow = document.createElement('tr');
      newRow.innerHTML = `
        <td></td>
        <td>${username}</td>
        <td>${email}</td>
        <td>
          <button class="btn btn-warning btn-sm me-2">Edit</button>
          <button class="btn btn-danger btn-sm">Eliminate</button>
        </td>
      `;
      tableBody.appendChild(newRow);
      updateRowNumbers();
    document.querySelector('.btn-close').click();
    } else {
    alert('Please fill in all fields');
    }
      alert('Please fill in all fields');
    }
  

  function deleteUser() {
    const row = document.querySelector('table tbody tr:last-child');
    row.remove();
    updateRowNumbers();
  }

  
  function updateRowNumbers() {
    const rows = document.querySelectorAll('table tbody tr');
    rows.forEach((row, index) => {
      row.querySelector('td').innerText = index + 1;
    });
  }
  
    document.querySelector('.btn-primary').addEventListener('click', saveUser);
    document.querySelector('.btn-primary').addEventListener('click', saveUser);
    document.querySelector('.btn-secondary').addEventListener('click', clearForm);
    document.querySelector('.btn-close').addEventListener('click', clearForm);