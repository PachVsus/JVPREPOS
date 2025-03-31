function paginate(items, page = 1, perPage = 10) {
    const start = (page - 1) * perPage;
    const end = start + perPage;
    return items.slice(start, end);
  }
  
  function renderPaginationControls(totalItems, perPage, containerId, onPageChange) {
    const totalPages = Math.ceil(totalItems / perPage);
    const container = document.getElementById(containerId);
    container.innerHTML = "";
  
    for (let i = 1; i <= totalPages; i++) {
      const btn = document.createElement("button");
      btn.textContent = i;
      btn.className = "btn btn-sm btn-primary m-1";
      btn.onclick = () => onPageChange(i);
      container.appendChild(btn);
    }
  }
  